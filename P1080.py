if __name__ == '__main__':
    n = int(input())
    left0, right0 = map(int, input().split())

    line = []
    for i in range(n):
        left, right = map(int, input().split())
        line.append([left, right])
    line.sort(key=lambda x: x[0]*x[1])
    line.insert(0, [left0, right0])
    max_num = 0
    left_amount = 1
    for i in range(1, len(line)):
        left_amount *= line[i-1][0]
        cur_num = left_amount//line[i][1]
        max_num = max(max_num, cur_num)
    print(max_num)
