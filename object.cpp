#include "object.hpp"
#include <QDebug>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Object::Object()
{
    // 空对象
}

Object::Object(const QString &path)
{
    _loadModel(path);
}

// 使用 Assimp 加载模型
void Object::_loadModel(const QString &path)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path.toStdString(),
                                             aiProcess_Triangulate |
                                                 aiProcess_FlipUVs |
                                                 aiProcess_GenSmoothNormals);



    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        qDebug() << "[ERROR] Assimp load model failed:" << importer.GetErrorString();
        return;
    }

    // 遍历所有网格
    for (unsigned int i = 0; i < scene->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[i];
        _processMesh(mesh, scene);
    }
    qDebug() << "[INFO] Assimp load model is done ";
    qDebug() << "[INFO] Mesh 顶点zu数:" << vertexCounts.size();
}

// 处理单个 Mesh，生成 vertices
void Object::_processMesh(aiMesh* mesh, const aiScene* scene)
{
    unsigned int vertexCount = mesh->mNumVertices;
    vertexCounts.push_back(vertexCount);   // 保存下来供渲染使用

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        // 1. 顶点位置
        vertices.push_back(mesh->mVertices[i].x);
        vertices.push_back(mesh->mVertices[i].y);
        vertices.push_back(mesh->mVertices[i].z);

        // 2. 法线
        if (mesh->HasNormals())
        {
            vertices.push_back(mesh->mNormals[i].x);
            vertices.push_back(mesh->mNormals[i].y);
            vertices.push_back(mesh->mNormals[i].z);
        }
        else
        {
            vertices.push_back(0.0f);
            vertices.push_back(0.0f);
            vertices.push_back(0.0f);
        }

        // 3. 纹理坐标
        if (mesh->mTextureCoords[0]) // Assimp 支持多组 UV
        {
            vertices.push_back(mesh->mTextureCoords[0][i].x);
            vertices.push_back(mesh->mTextureCoords[0][i].y);
        }
        else
        {
            vertices.push_back(0.0f);
            vertices.push_back(0.0f);
        }
    }
    qDebug() << "[INFO] Mesh 顶点数:" << vertexCount;
}
