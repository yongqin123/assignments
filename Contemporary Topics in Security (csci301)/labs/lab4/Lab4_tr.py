import json

transactions = [ "[3, 4, 5, 6]", "[4, 5, 6, 7]", "[5, 6, 7, 8]", "[6, 7, 8, 9]", "[7, 8, 9, 10]", "[8, 9, 10, 11]", "[9, 10, 11, 12]", "[10, 11, 12, 13]", "[11, 12, 13, 14]", "[12, 13, 14, 15]", "[13, 14, 15, 16]"]

block = {"Block number": 0, "Hash": "Genesis", "Transaction": ""}


print(json.dumps({' Block number ': 0, ' Hash':
"Genesis", 'Transaction': ""}, sort_keys=True,
indent=4, separators=(',', ': ')))
for i in range(len(transactions)):
        fw = open(str(i) + ".json", "w+")
        fw.write(transactions[i])
        fw.close()
        
