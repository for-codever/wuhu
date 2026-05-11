#include "campus_nav.h"

// 4. 热度图功能实现：队列实现滑动窗口热度统计
unordered_map<int, int> CampusNav::getHotMap() {
    unordered_map<int, int> hotCount;
    queue<Point> tempQueue = visitFlowQueue;

    // 遍历流水队列统计访问频次
    while (!tempQueue.empty()) {
        int id = tempQueue.front().id;
        hotCount[id]++;
        tempQueue.pop();
    }
    return hotCount;
}

void CampusNav::showHotRank() {
    unordered_map<int, int> hotMap = getHotMap();
    if (hotMap.empty()) {
        cout << "[提示] 暂无访问数据，无法生成热度排行" << endl;
        return;
    }

    // 热度降序排序
    vector<pair<int, int>> hotVec(hotMap.begin(), hotMap.end());
    sort(hotVec.begin(), hotVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });

    cout << "===== 校园地点热度排行 =====" << endl;
    for (int i = 0; i < hotVec.size(); i++) {
        cout << i + 1 << ". " << pointMap[hotVec[i].first].name
            << " | 访问次数：" << hotVec[i].second << endl;
    }
}