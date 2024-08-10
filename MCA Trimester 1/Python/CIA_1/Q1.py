#Q1 landmarks

def reconstruct_path(l1,ordered_part,jumbled_part):
    for i in range(len(l1)):
        if l1[i]==ordered_part[0]:
            start=i
        if l1[i]==ordered_part[1]:
            end=i
    l1[start+1:end]=jumbled_part
    return l1

l1=['Start','Clearing','River','Village','Cave']

ordered_part=['Start','River']
jumbled_part=['Clearing','Village','Cave']

print(f'Existing Orderded path {ordered_part}: \n Jumbled_path: {jumbled_part} \n New Ordered Path: {reconstruct_path(l1,ordered_part,jumbled_part)}')

