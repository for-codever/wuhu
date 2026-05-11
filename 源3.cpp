#include "campus_nav.h"

// 3. 模糊搜功能实现：队列实现BFS全地点遍历匹配
vector<Point> CampusNav::fuzzySearch(const string& keyword) {
    vector<Point> result;
    if (pointMap.empty()) {
        cout << "[错误] 暂无地点数据，搜索失败" << endl;
        return result;
    }
    queue<int> bfsQueue;
    unordered_map<int, bool> visited;

    // 初始化BFS队列
    for (auto& pair : pointMap) {
        bfsQueue.push(pair.first);
        visited[pair.first] = false;
    }

    // BFS遍历匹配关键词
    while (!bfsQueue.empty()) {
        int curId = bfsQueue.front();
        bfsQueue.pop();

        if (visited[curId]) continue;
        visited[curId] = true;

        Point& curPoint = pointMap[curId];
        // 模糊匹配规则：名称/描述包含关键词即命中
        if (curPoint.name.find(keyword) != string::npos
            || curPoint.desc.find(keyword) != string::npos) {
            result.push_back(curPoint);
        }

        // 邻接节点入队，支持图结构遍历
        for (int adjId : curPoint.adj) {
            if (!visited[adjId]) {
                bfsQueue.push(adjId);
            }
        }
    }

    cout << "[搜索] 关键词[" << keyword << "]，共找到" << result.size() << "个结果" << endl;
    return result;
}