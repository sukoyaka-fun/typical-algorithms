import random

def generate_test_case(n, m, s, t):
    # ヘッダー部を作成
    test_case = f"{n} {m}\n{s} {t}\n"
    
    # 辺の情報をランダムに生成
    for _ in range(m):
        u = random.randint(1, n)  # 頂点u (1からnまで)
        v = random.randint(1, n)  # 頂点v (1からnまで)
        while v == u:  # uとvは異なる頂点でなければならない
            v = random.randint(1, n)
        w = random.randint(1, 10)  # 重みw (1から10まで)
        
        # 辺の情報を追加
        test_case += f"{u} {v} {w}\n"
    
    return test_case

def write_test_case_to_file(filename, n, m, s, t):
    test_case = generate_test_case(n, m, s, t)
    with open(filename, 'w') as file:
        file.write(test_case)

# テストケースを生成し、input.txt に書き込む
n = 4  # 頂点数
m = 5  # 辺の数
s = 1  # スタート頂点
t = 4  # ゴール頂点

write_test_case_to_file("input.txt", n, m, s, t)

