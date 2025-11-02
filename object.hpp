#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>
#include <QString>
#include <QVector3D>
#include <QMatrix4x4>

class Object
{
public:
    Object();
    Object(const QString &path); // 从文件加载模型

    std::vector<float> vertices;   // 顶点数据：x,y,z,nx,ny,nz,u,v
    QMatrix4x4 mat_model;          // 模型矩阵
    std::vector<unsigned int> vertexCounts; // 保存每个mesh的顶点数量


private:
    void _loadModel(const QString &path);
    void _processMesh(aiMesh* mesh, const aiScene* scene);
};

#endif // OBJECT_HPP
