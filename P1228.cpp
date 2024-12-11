// DONE
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

void fill(int length, int square_x, int square_y, int filled_x, int filled_y){
//    square_x, square_y用于确定正方形左上角位置
    if(length == 1)
        return;
    if(filled_x < square_x + length/2 && filled_y < square_y + length/2){
//        已填充的在左上角
        cout << square_x+length/2 << " "
            << square_y+length/2 << " "
            << 1 << "\n";
        fill(length/2, square_x, square_y, filled_x, filled_y);
        fill(length/2, square_x, square_y+length/2, square_x+length/2-1, square_y+length/2);
        fill(length/2, square_x+length/2, square_y, square_x+length/2, square_y+length/2-1);
        fill(length/2, square_x+length/2, square_y+length/2, square_x+length/2, square_y+length/2);
    }else if(filled_x < square_x + length/2 && filled_y >= square_y + length/2){
//        已填充的在右上角
        cout << square_x+length/2 << " "
             << square_y+length/2-1 << " "
             << 2 << "\n";
        fill(length/2, square_x, square_y, square_x+length/2-1, square_y+length/2-1);
        fill(length/2, square_x, square_y+length/2, filled_x, filled_y);
        fill(length/2, square_x+length/2, square_y, square_x+length/2, square_y+length/2-1);
        fill(length/2, square_x+length/2, square_y+length/2, square_x+length/2, square_y+length/2);
    }else if(filled_x >= square_x + length/2 && filled_y < square_y + length/2){
//        已填充左下角
        cout << square_x+length/2-1 << " "
             << square_y+length/2 << " "
             << 3 << "\n";
        fill(length/2, square_x, square_y, square_x+length/2-1, square_y+length/2-1);
        fill(length/2, square_x, square_y+length/2, square_x+length/2-1, square_y+length/2);
        fill(length/2, square_x+length/2, square_y, filled_x, filled_y);
        fill(length/2, square_x+length/2, square_y+length/2, square_x+length/2, square_y+length/2);
    }else{
        cout << square_x+length/2-1 << " "
             << square_y+length/2-1 << " "
             << 4 << "\n";
        fill(length/2, square_x, square_y, square_x+length/2-1, square_y+length/2-1);
        fill(length/2, square_x, square_y+length/2, square_x+length/2-1, square_y+length/2);
        fill(length/2, square_x+length/2, square_y, square_x+length/2, square_y+length/2-1);
        fill(length/2, square_x+length/2, square_y+length/2, filled_x, filled_y);
    }
}

int main(){
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, x, y;
    cin >> k >> x >> y;
    fill(std::pow(2,k), 1, 1, x, y);
    return 0;
}