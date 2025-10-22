#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

// 2D 격자의 한 셀을 나타내는 Node 구조체
struct Node {
    int x, y;
    bool isObstacle;
    double g, h, f;
    Node* parent;
    bool closed, open;
    
    Node(int _x, int _y, bool obs = false)
    : x(_x), y(_y), isObstacle(obs),
      g(numeric_limits<double>::infinity()),
      h(0), f(numeric_limits<double>::infinity()),
      parent(nullptr), closed(false), open(false) {}
};

const int ROWS = 10;
const int COLS = 20;

double heuristic(const Node* a, const Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->f > b->f;
    }
};

vector<Node*> getNeighbors(Node* current, vector<vector<Node>>& grid) {
    vector<Node*> neighbors;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    for (int i = 0; i < 4; i++) {
        int nx = current->x + dx[i];
        int ny = current->y + dy[i];
        if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS)
            neighbors.push_back(&grid[ny][nx]);
    }
    return neighbors;
}

vector<Node*> reconstructPath(Node* goal) {
    vector<Node*> path;
    Node* current = goal;
    while (current != nullptr) {
        path.push_back(current);
        current = current->parent;
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<Node*> AStar(vector<vector<Node>>& grid, Node* start, Node* goal) {
    // Reset grid values for A*
    for(auto& row: grid)
        for(auto& node: row) {
            node.g = numeric_limits<double>::infinity();
            node.f = numeric_limits<double>::infinity();
            node.parent = nullptr;
            node.closed = false;
            node.open = false;
        }
    
    priority_queue<Node*, vector<Node*>, CompareNode> openList;
    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    openList.push(start);
    start->open = true;
    
    while (!openList.empty()){
        Node* current = openList.top();
        openList.pop();
        current->open = false;
        current->closed = true;
        
        if (current == goal)
            return reconstructPath(goal);
        
        vector<Node*> neighbors = getNeighbors(current, grid);
        for (auto neighbor : neighbors) {
            if (neighbor->isObstacle || neighbor->closed)
                continue;
            
            double tentative_g = current->g + 1;
            if (tentative_g < neighbor->g) {
                neighbor->parent = current;
                neighbor->g = tentative_g;
                neighbor->h = heuristic(neighbor, goal);
                neighbor->f = neighbor->g + neighbor->h;
                if (!neighbor->open) {
                    openList.push(neighbor);
                    neighbor->open = true;
                }
            }
        }
    }
    return vector<Node*>();
}

void printGrid(const vector<vector<Node>>& grid, const vector<Node*>& path, Node* npc, Node* start, Node* goal) {
    vector<vector<char>> display(ROWS, vector<char>(COLS, '.'));
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (grid[i][j].isObstacle)
                display[i][j] = '#';
                
    // 경로 표시 (경로상의 노드 'o')
    for(auto node: path) {
        display[node->y][node->x] = 'o';
    }
    // 시작점과 목표점 표시
    display[start->y][start->x] = 'S';
    display[goal->y][goal->x] = 'G';
    
    // NPC 표시
    if (npc)
        display[npc->y][npc->x] = 'N';
    
    // 격자 출력
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            cout << display[i][j] << " ";
        cout << endl;
    }
}

int main() {
    // 격자 생성
    vector<vector<Node>> grid;
    for (int i = 0; i < ROWS; i++) {
        vector<Node> row;
        for (int j = 0; j < COLS; j++) {
            row.push_back(Node(j, i));
        }
        grid.push_back(row);
    }
    
    // 장애물 설정: 4행의 열 3~15를 장애물로 설정하지만 출입구를 열어놓음
    for (int j = 3; j <= 15; j++)
        grid[4][j].isObstacle = true;
    grid[4][3].isObstacle = false;
    grid[4][15].isObstacle = false;
    
    // 시작점과 목표점 설정
    Node* start = &grid[0][0];
    Node* goal = &grid[9][19];
    
    // NPC 초기 위치는 시작점
    Node* npc = start;
    
    // 초기에 전체 경로 계산
    vector<Node*> path = AStar(grid, npc, goal);
    if(path.empty()){
        cout << "경로가 없습니다." << endl;
        return 0;
    }
    
    // 게임 루프 유사: NPC가 경로를 따라 이동하면서 계속 업데이트
    // 각 단계마다 엔터 키로 진행 (실제 게임에서는 타이머 기반으로 자동 업데이트)
    for (int i = 0; i < path.size(); i++) {
        npc = path[i];  // NPC는 경로를 따라 한 셀씩 이동
        system("clear"); // 화면 지우기 (Unix 환경, Windows는 "cls")
        cout << "NPC 이동: 단계 " << i+1 << " / " << path.size() << endl;
        printGrid(grid, path, npc, start, goal);
        cout << "\n엔터 키를 누르세요...";
        cin.get();
        
        // (여기서 필요하면 환경 변화 등으로 인해 경로를 재계산할 수도 있음)
    }
    
    cout << "\nNPC가 목표에 도달했습니다!" << endl;
    return 0;
}
