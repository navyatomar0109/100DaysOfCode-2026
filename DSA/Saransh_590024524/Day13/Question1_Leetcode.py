class Solution:
    def mostCommonWord(self, paragraph, banned):
        dic = {}

        paragraph = paragraph.lower()

        for ch in "!?',;.":
            paragraph = paragraph.replace(ch, " ")

        p = paragraph.split()

        for i in p:
            if i in banned:
                continue
            if i not in dic:
                dic[i] = 1
            else:
                dic[i] += 1 
        
        return max(dic,key= dic.get)        