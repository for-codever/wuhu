#include "campus_nav.h"

// 6. 能排序功能实现：双栈实现自定义规则排序
vector<Point> CampusNav::sortPointsByRule(int rule) {
    vector<Point> sortedResult;
    if (pointQueue.empty()) {
        cout << "[错误] 暂无地点数据，排序失败" << endl;
        return sortedResult;
    }

    stack<Point> dataStack;  // 数据栈
    stack<Point> helpStack;  // 排序辅助栈
    queue<Point> tempQueue = pointQueue;

    // 地点数据入栈
    while (!tempQueue.empty()) {
        dataStack.push(tempQueue.front());
        tempQueue.pop();
    }

    // 双栈排序核心逻辑
    while (!dataStack.empty()) {
        Point curPoint = dataStack.top();
        dataStack.pop();

        // 按规则调整栈内元素顺序
        while (!helpStack.empty()) {
            Point topPoint = helpStack.top();
            bool needPop = false;

            switch (rule) {
            case 1: needPop = curPoint.name < topPoint.name; break; // 名称字典序升序
            case 2: needPop = curPoint.hot > topPoint.hot; break;   // 热度降序
            case 3: needPop = curPoint.id < topPoint.id; break;     // ID升序
            default: needPop = curPoint.id < topPoint.id; break;
            }

            if (needPop) {
                dataStack.push(topPoint);
                helpStack.pop();
            }
            else {
                break;
            }
        }
        helpStack.push(curPoint);
    }

    // 生成排序结果
    while (!helpStack.empty()) {
        sortedResult.push_back(helpStack.top());
        helpStack.pop();
    }
    reverse(sortedResult.begin(), sortedResult.end());

    // 输出结果
    cout << "===== 排序结果 =====" << endl;
    for (int i = 0; i < sortedResult.size(); i++) {
        cout << i + 1 << ". " << sortedResult[i].name;
        if (rule == 2) cout << " | 热度：" << sortedResult[i].hot;
        cout << endl;
    }

    return sortedResult;
}