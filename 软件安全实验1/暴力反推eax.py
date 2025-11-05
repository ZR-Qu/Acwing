def simulate_with_eax(initial_eax):
    # 设定初始值
    initial_di = 0x0001
    initial_si = 0x006E
    mem_local_68_start = 0x9320
    mem_local_71 = 0xAC52
    
    # 模拟32位寄存器
    MASK_32 = 0xFFFFFFFF
    
    eax = initial_eax
    ebx = 0
    ecx = 0
    edx = 0
    esi = 0
    edi = 0
    
    mem_local_68 = mem_local_68_start
    mem_local_67 = 0
    
    ebx = eax                       # mov ebx,eax
    edi = initial_di & 0xFFFF       # movzx edi,di
    eax = initial_si & 0xFFFF       # movzx eax,si
    ecx = ebx                       # mov ecx,ebx
    mem_local_67 = eax              # mov [local.67],eax
    ecx = (ecx + 0xF00) & MASK_32   # add ecx,0xF00
    eax = mem_local_68              # mov eax,[local.68]
    edx = edi                       # mov edx,edi
    edx = (edx - ecx) & MASK_32     # sub edx,ecx
    esi = eax & 0xFFFF              # movzx esi,ax
    ecx = mem_local_67              # mov ecx,[local.67]
    eax = ebx                       # mov eax,ebx
    ecx = (ecx + esi) & MASK_32     # add ecx,esi
    eax = eax & 0xF000              # and eax,0xF000
    ecx = (ecx + edi) & MASK_32     # add ecx,edi
    eax = (eax + esi) & MASK_32     # add eax,esi
    ecx = (ecx + ebx) & MASK_32     # add ecx,ebx
    eax = eax & 0xF000              # and eax,0xF000
    edx = edx & 0xF00               # and edx,0xF00
    ecx = ecx & 0xF                 # and ecx,0xF
    edx = (edx + ecx) & MASK_32     # add edx,ecx
    ecx = mem_local_71              # mov ecx,[local.71]
    edx = (edx + eax) & MASK_32     # add edx,eax
    eax = mem_local_67              # mov eax,[local.67]
    eax = (eax ^ ebx) & MASK_32     # xor eax,ebx
                                    # mov word ptr ds:[0x450004],cx (无关)
                                    # mov ebx,[local.72] (无关)
    eax = eax & 0xF0                # and eax,0xF0
    edx = (edx + eax) & MASK_32     # add edx,eax
    edx = (edx ^ 0xAFDA) & MASK_32  # xor edx,0xAFDA
    eax = edx & 0xFFFF              # movzx eax,dx
    mem_local_68 = eax              # mov [local.68],eax

    return mem_local_68

def find_eax_solutions(target_local_68_value):
    print(f"开始求解：目标 [local.68] = {hex(target_local_68_value)}")
    print("正在搜索所有可能的 initial_eax (低16位)...")
    
    solutions = []
    # 遍历 0x0000 到 0xFFFF
    for eax_low_16 in range(0x10000):
        final_value = simulate_with_eax(eax_low_16)
        
        if final_value == target_local_68_value:
            print(f"  [+] 找到解！eax 的低 16 位 = {hex(eax_low_16)}")
            solutions.append(eax_low_16)
            
    return solutions

TARGET_VALUE = 0x938 

found_solutions = find_eax_solutions(TARGET_VALUE)

print("--- 总结 ---")
if not found_solutions:
    print(f"未找到任何 initial_eax 值可以产生 {hex(TARGET_VALUE)}。")
else:
    print(f"找到了 {len(found_solutions)} 个可能的 eax 低 16 位值。")
    print(f"所有解: {[hex(s) for s in found_solutions]}")