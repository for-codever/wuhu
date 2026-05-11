#include "campus_nav.h"

// 功能测试主函数
int main() {
    CampusNav nav;

    cout << "========== 1. 存地点功能测试 ==========" << endl;
    nav.addPoint(1, "一号教学楼", "主教学楼，含多个阶梯教室", 10, 20);
    nav.addPoint(2, "图书馆", "校园中心图书馆，藏书100万册", 15, 25);
    nav.addPoint(3, "一食堂", "校园第一食堂，提供各地美食", 20, 30);
    nav.addPoint(4, "二号宿舍楼", "学生二号公寓楼", 25, 35);
    nav.addPoint(5, "操场", "校园主体育场，含足球场和跑道", 30, 40);
    cout << endl;

    cout << "========== 路径连通配置 ==========" << endl;
    nav.addPath(1, 2);
    nav.addPath(2, 3);
    nav.addPath(3, 4);
    nav.addPath(4, 5);
    nav.addPath(1, 3);
    cout << endl;

    cout << "========== 2. 记历史功能测试 ==========" << endl;
    nav.addVisitHistory(nav.getPoint(1));
    nav.addVisitHistory(nav.getPoint(2));
    nav.addVisitHistory(nav.getPoint(3));
    nav.showHistory();
    nav.goBackHistory();
    nav.showHistory();
    cout << endl;

    cout << "========== 3. 模糊搜功能测试 ==========" << endl;
    vector<Point> searchRes = nav.fuzzySearch("楼");
    for (auto& p : searchRes) {
        cout << "- " << p.name << "：" << p.desc << endl;
    }
    cout << endl;

    cout << "=4. 热度图功能测试  << endl;
    nav.addVisitHistory(nav.getPoint(3));
    nav.addVisitHistory(nav.getPoint(3));
    nav.addVisitHistory(nav.getPoint(5));
    nav.showHotRank();
    cout << endl;

    cout << "= 5. 找路径功能测试" << endl;
    nav.findShortestPath(1, 5);
    cout << endl;

    cout << "=6. 排序功能测试  "<< endl;
    cout << "按热度降序排序”<<endl;
    cout << "----- 按名称字典序排序 -----" << endl;
    nav.sortPointsByRule(1);

    return 0;
}