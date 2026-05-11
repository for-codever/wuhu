#include "campus_nav.h"

// Point结构体构造函数实现
Point::Point(int id_, string name_, string desc_, int x, int y)
    : id(id_), name(name_), desc(desc_), hot(0), pos({ x, y }) {
}

// 辅助API：添加地点间连通路径
void CampusNav::addPath(int id1, int id2) {
    if (!pointMap.count(id1) || !pointMap.count(id2)) {
        cout << "[错误] 地点ID不存在，添加路径失败" << endl;
        return;
    }
    pointMap[id1].adj.push_back(id2);
    pointMap[id2].adj.push_back(id1);
    cout << "[成功] 已添加[" << pointMap[id1].name << "]与[" << pointMap[id2].name << "]的路径" << endl;
}

// 辅助API：获取地点对象
Point CampusNav::getPoint(int id) {
    if (pointMap.count(id)) {
        return pointMap[id];
    }
    return Point(-1, "", "", 0, 0);
}