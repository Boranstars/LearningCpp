#!/bin/bash

# 获取文件名和目录
WORKSPACE_FOLDER=$1
FILE_PATH=$2
FILE_DIR=$(dirname "$FILE_PATH") #dirname 获取去除路径最后一部分的目录
FILE_BASENAME=$(basename "$FILE_PATH" .cpp) #basename 获取路径最后一部分
FILE_DIR_BASENAME = $(basename "$FILE_DIR")

# 检查路径中是否包含/src/
if [[ "$FILE_PATH" == *"/src/"* ]]; then
    # 包含/src/，计算从src目录开始的相对路径
    RELATIVE_PATH=${FILE_PATH#*$WORKSPACE_FOLDER/src/}
    RELATIVE_DIR=$(dirname "$RELATIVE_PATH")
    OUT_DIR="$WORKSPACE_FOLDER/build/$RELATIVE_DIR"
else
    # 不包含/src/，使用当前目录名和无扩展名文件名
    OUT_DIR="$WORKSPACE_FOLDER/build/$FILE_DIR_BASENAME"
fi

# 创建输出目录（如果不存在）
mkdir -p "$OUT_DIR"

# 编译命令
g++ -fdiagnostics-color=always -g "$FILE_PATH" -o "$OUT_DIR/$FILE_BASENAME"
echo $FILE_DIR
echo $(basename "$FILE_DIR")
echo "编译完成: $OUT_DIR/$FILE_BASENAME"