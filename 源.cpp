#ifndef CAMPUS_NAV_H
#define CAMPUS_NAV_H

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 校园地点结构体
struct Point {
    int id;             // 地点唯一ID
    string name;        // 地点名称
    string desc;        // 地点描述
    int hot;            // 访问热度
    pair<int, int> pos; // 坐标(x,y)
    vector<int> adj;    // 邻接节点ID（路径连通的地点）

    // 构造函数声明
    Point(int id_ = -1, string name_ = "", string desc_ = "", int x = 0, int y = 0);
};

// 校园导航系统核心类
class CampusNav {
private:
    unordered_map<int, Point> pointMap;  // 全地点映射 ID->Point
    stack<Point> historyStack;           // 访问历史栈（记历史功能）
    queue<Point> pointQueue;              // 地点存储队列（存地点功能）
    queue<Point> visitFlowQueue;          // 访问流水队列（热度图功能）
    int maxFlowSize = 100;                // 热度统计滑动窗口上限

public:
   
    bool addPoint(int id, string name, string desc, int x, int y);
    
    void addVisitHistory(const Point& p);
    Point goBackHistory();
    void showHistory();
    
    vector<Point> fuzzySearch(const string& keyword);

    unordered_map<int, int> getHotMap();
    void showHotRank();
    vector<Point> findShortestPath(int startId, int endId);
  
    vector<Point> sortPointsByRule(int rule);

    void addPath(int id1, int id2);
    Point getPoint(int id);
};

#endif // CAMPUS_NAV_H