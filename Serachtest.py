import urllib.request as req
url="https://www.coolpc.com.tw/evaluate.php"
request=req.Request(url, headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.164 Safari/537.36"
})
with req.urlopen(request) as response:
    data=response.read().decode("cp950")

with open("原價屋.txt",mode="w",encoding="cp950") as file:
    for line in data:
        file.write(line)