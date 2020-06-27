import os
from PIL import Image


def save_resize_img(img_path, img_path_train, width, height):
    if not os.path.exists(img_path_train):
        os.mkdir(img_path_train)
    for label_name in os.listdir(img_path):
        if not os.path.exists(img_path_train + label_name + '/'):
            os.mkdir(img_path_train + label_name + '/')
        for imgs_name in os.listdir(img_path + label_name):
            img = (Image.open(img_path + label_name + '/' + imgs_name))
            img = img.resize((width, height), Image.ANTIALIAS)
            img.save(img_path_train + label_name + '/' + imgs_name)


if __name__ == '__main__':
    # save_resize_img(
    #     "D:/HMGJ/firmware/stm32-projects/App/Display_vulture/assets/images/", "D:/image/", 1, 1)
    save_resize_img(
        "D:/HMGJ/firmware/stm32-projects/App/Display_vulture/assets/images/pyh-dial/", "D:/image/pyh-dial/", 1, 1)
