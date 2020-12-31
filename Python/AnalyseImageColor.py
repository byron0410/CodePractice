'''
利用pillow的Image.getcolors进行检测：
https://pillow.readthedocs.io/en/stable/_modules/PIL/Image.html#Image.getcolors
当图片颜色大于256时，接口返回None
'''
import os
from PIL import Image


def getColorNums(img_path):
    doc = open('color.txt', 'w')
    target = 0
    total = 0
    print("The image path which over 256 color:", file=doc)
    for label_name in os.listdir(img_path):
        for imgs_name in os.listdir(img_path + label_name):
            try:
                total = total + 1
                img = (Image.open(img_path + label_name + '/' + imgs_name))
                result = img.getcolors(maxcolors=256)
                if result is None:
                    print("assets_lisbon/images/", label_name, '/', imgs_name, sep='', file=doc)
                    target = target + 1
            except OSError:
                total = total - 1
                pass
            continue
    if total != 0:
        print("total=", total, "target=", target, "target/total=", target/total, file=doc)


if __name__ == '__main__':
    getColorNums("D:/HMGJ/GT2/stm32-projects/App/Display_g2/assets_lisbon/images/")
