import numpy as np

def input_matrix(name, rows, cols):
    print(f"请输入矩阵{name}，共{rows}行{cols}列，每行输入{cols}个整数，用空格分隔：")
    matrix = []
    for i in range(rows):
        while True:
            try:
                row = list(map(int, input(f"{name} 第{i+1}行: ").split()))
                if len(row) != cols:
                    print(f"请确保输入{cols}个整数。")
                    continue
                matrix.append(row)
                break
            except ValueError:
                print("输入无效，请输入整数。")
    return np.array(matrix)

def matrix_mod_mul(A, B, modulus=26):
    return np.dot(A, B) % modulus

def main():
    # 输入矩阵A的尺寸
    while True:
        try:
            rA = int(input("请输入矩阵A的行数: "))
            cA = int(input("请输入矩阵A的列数: "))
            if rA <= 0 or cA <= 0:
                print("行数和列数必须为正整数。")
                continue
            break
        except ValueError:
            print("请输入有效的整数。")

    # 输入矩阵B的尺寸
    while True:
        try:
            rB = int(input("请输入矩阵B的行数: "))
            cB = int(input("请输入矩阵B的列数: "))
            if rB <= 0 or cB <= 0:
                print("行数和列数必须为正整数。")
                continue
            if rB != cA:
                print(f"矩阵B的行数必须等于矩阵A的列数({cA})，才能相乘。")
                continue
            break
        except ValueError:
            print("请输入有效的整数。")

    A = input_matrix("A", rA, cA)
    B = input_matrix("B", rB, cB)

    C = matrix_mod_mul(A, B, 26)
    print(f"矩阵A * 矩阵B 在mod 26下的结果是（{rA}x{cB}矩阵）：")
    print(C)

if __name__ == "__main__":
    main()
