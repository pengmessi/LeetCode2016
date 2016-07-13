//
// Created by hf46p on 2016/6/9.
//https://leetcode.com/problems/design-snake-game/
//

#include "IncludeHelper.h";

using namespace std;

pair<int,int> operator+ (const pair<int,int> &a, const pair<int,int> &b) {
    return make_pair(a.first+b.first, a.second+b.second);
}

class SnakeGame {
private:
    vector<pair<int, int>> food;
    int foodi = 0;
    queue<pair<int, int>> que;
    unordered_map<char, pair<int, int>> dir;
    int width, height;
    bool gameover;
    unordered_set<int> st;

public:

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food):food(food),foodi(0),width(width),height(height),gameover(false) {
        que.push(make_pair(0,0));
        dir['U'] = make_pair(-1, 0);
        dir['L'] = make_pair( 0,-1);
        dir['R'] = make_pair( 0, 1);
        dir['D'] = make_pair( 1, 0);
        st.insert(0);
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> p = que.back() + dir[direction[0]];

        if (gameover || p.first <0 || p.first >= height || p.second <0 || p.second >= width) {
            gameover = true;
            return -1;
        }
        if (foodi < food.size() && p == food[foodi]) {
            ++foodi;
        } else {
            st.erase(width*que.front().first+que.front().second);
            que.pop();
        }

        if (st.find(width*p.first+p.second) == st.end()) {
            que.push(p);
            st.insert(width*p.first+p.second);
        } else {
            gameover = true;
            return -1;
        }

        return que.size() - 1;
    }
};

//pair<int,int> operator+ (const pair<int,int> &a, const pair<int,int> &b) {
//    return make_pair(a.first+b.first, a.second+b.second);
//}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
