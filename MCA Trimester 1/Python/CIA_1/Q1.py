ordered_part = ['Start', 'River']
jumbled_part = ['Clearing', 'Village', 'Cave']
ordered_path = []

def reconstruct_path(l1, l2):
    max_len = max(len(l1), len(l2))
    for i in range(max_len):
        if i < len(l1):
            ordered_path.append(l1[i])
        if i < len(l2):
            ordered_path.append(l2[i])
    
    print(ordered_path)

reconstruct_path(ordered_part, jumbled_part)