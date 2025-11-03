def adjoint_matrix_2x2(matrix):
    a, b = matrix[0]
    c, d = matrix[1]
    return [
        [d, -b],
        [-c, a]
    ]

def main():
    print("请输入一个 2×2 矩阵（按行输入，每行输入两个数字，用空格分隔）：")
    matrix = []
    for i in range(2):
        row = input(f"输入第 {i+1} 行：").strip().split()
        if len(row) != 2:
            print("每行必须输入两个数字。程序结束。")
            return
        try:
            matrix.append([float(x) for x in row])
        except ValueError:
            print("输入无效，请输入数字。程序结束。")
            return

    adj = adjoint_matrix_2x2(matrix)

    print("\n原矩阵 A：")
    for row in matrix:
        print(row)

    print("\n伴随矩阵 adj(A)：")
    for row in adj:
        print(row)

if __name__ == "__main__":
    main()
