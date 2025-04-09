#pragma once

#include <utility>

namespace ObjMesh
{
    //큐브 정점 배열포인터, 크기를 바위트 단위로 변환
    std::pair<const float*, size_t> GetObjVertices();
}