import PyPDF2
import sys

pdfReader = PyPDF2.PdfFileReader(open("encrypted.pdf", "rb"))
if pdfReader.isEncrypted:
    # 开始破解密码
    print("尝试破解密码...")
    # 获取密码字典
    File = open("num.txt")
    sfile = File.read()
    dic = sfile.split("\n")
    num = len(dic)
    for i in range(num):
        print("第 " + str(i) + " 次尝试...     ", end=" ")
        if pdfReader.decrypt(dic[i]):
            print("破解成功，密码是 " + dic[i] + "...")
            # 进入PDF
            print("PDF有 " + str(pdfReader.numPages) + "...")
            print("内容摘要")
            pageObj = pdfReader.getPage(0)
            print(pageObj.extractText())
            break
        temp = dic[i].lower()
        if pdfReader.decrypt(temp):
            print("破解成功，密码是 " + temp + "...")
            # 进入PDF
            print("PDF有 " + str(pdfReader.numPages) + "...")
            print("内容摘要")
            pageObj = pdfReader.getPage(0)
            print(pageObj.extractText())
            break
        print("失败")
    print("程序关闭...")
    sys.exit()
