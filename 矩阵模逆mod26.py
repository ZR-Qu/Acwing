import numpy as np

def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = egcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

def mod_inv(a, m):
    g, x, _ = egcd(a, m)
    if g != 1:
        return None  # 不可逆
    else:
        return x % m

def matrix_mod_inv(matrix, modulus):
    det = int(round(np.linalg.det(matrix))) % modulus
    inv_det = mod_inv(det, modulus)
    if inv_det is None:
        return None  # 行列式不可逆，整个矩阵在模m下不可逆

    n = matrix.shape[0]
    cofactors = np.zeros((n, n), dtype=int)

    for r in range(n):
        for c in range(n):
            minor = np.delete(np.delete(matrix, r, axis=0), c, axis=1)
            cofactors[r][c] = ((-1) ** (r + c)) * int(round(np.linalg.det(minor)))

    adjugate = cofactors.T % modulus
    inv_matrix = (inv_det * adjugate) % modulus
    return inv_matrix

def main():
    try:
        n = int(input("请输入矩阵的维度 n（表示 n×n）："))
        modulus = int(input("请输入模数 m："))
        if n <= 0 or modulus <= 1:
            print("维度必须为正整数，模数必须大于1。")
            return
    except ValueError:
        print("请输入有效的整数。")
        return

    print(f"请输入 {n}×{n} 矩阵的每一行，每行输入 {n} 个整数，用空格分隔：")
    matrix = []
    for i in range(n):
        while True:
            try:
                row = list(map(int, input(f"第{i+1}行: ").split()))
                if len(row) != n:
                    print(f"请确保输入 {n} 个整数。")
                    continue
                matrix.append(row)
                break
            except ValueError:
                print("输入无效，请输入整数。")

    mat_np = np.array(matrix)
    inv_mat = matrix_mod_inv(mat_np, modulus)

    print("\n原矩阵为：")
    print(mat_np)

    if inv_mat is None:
        print(f"\n该矩阵在模 {modulus} 下不可逆（行列式无逆元）。")
    else:
        print(f"\n该矩阵在模 {modulus} 下的逆矩阵为：")
        print(inv_mat)

if __name__ == "__main__":
    main()
