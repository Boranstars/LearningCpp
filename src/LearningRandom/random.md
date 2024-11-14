---
title: 使用 C++ `<random>` 库生成随机数
author: ChatGPT
date: 2024-04-27
---

# 使用 C++ `<random>` 库生成随机数

C++ 的 `<random>` 库自 C++11 引入以来，提供了一套功能强大且灵活的随机数生成机制，取代了传统的 `rand()` 和 `srand()` 函数。它不仅提供了多种随机数引擎和分布，还允许更精确地控制随机数生成过程。以下是对 C++ `<random>` 库的详细介绍，包括其组成部分、使用方法及示例代码。

## 目录

1. [随机数生成的基本概念](#随机数生成的基本概念)
2. [随机数引擎（Engines）](#随机数引擎)
3. [随机数分布（Distributions）](#随机数分布)
4. [随机数生成的步骤](#随机数生成的步骤)
5. [示例代码](#示例代码)
    - [生成均匀分布的整数](#生成均匀分布的整数)
    - [生成均匀分布的浮点数](#生成均匀分布的浮点数)
    - [生成正态分布的随机数](#生成正态分布的随机数)
    - [生成离散分布的随机数](#生成离散分布的随机数)
6. [高级用法](#高级用法)
    - [自定义随机数引擎和分布](#自定义随机数引擎和分布)
    - [生成随机序列](#生成随机序列)
7. [注意事项](#注意事项)
8. [总结](#总结)

---

## 随机数生成的基本概念

在 C++ `<random>` 库中，随机数生成通常涉及以下几个步骤：

1. **选择一个随机数引擎（Engine）：** 负责生成随机数的基础序列。
2. **选择一个随机数分布（Distribution）：** 将引擎生成的随机数转换为特定分布的值。
3. **生成随机数：** 通过引擎和分布组合生成所需的随机数。

这样的设计提供了高度的灵活性和可扩展性，使得用户可以根据需求选择不同的引擎和分布组合。

## 随机数引擎

随机数引擎负责生成均匀分布的伪随机数序列。C++ 提供了多种引擎，常用的包括：

- **线性同余引擎（Linear Congruential Engines）**
  - `std::minstd_rand`
  - `std::minstd_rand0`

- **梅森旋转算法引擎（Mersenne Twister Engines）**
  - `std::mt19937`（32 位版本，周期为 2³¹⁹⁹³⁷−1）
  - `std::mt19937_64`（64 位版本）

- **线性反馈移位寄存器引擎（Linear Feedback Shift Register Engines）**
  - `std::linear_congruential_engine`

- **其他引擎**
  - `std::ranlux24_base`, `std::ranlux48_base`（Lüssenheim-Roth算法）
  - `std::knuth_b`

**推荐使用：**

- **`std::mt19937`**：广泛使用，具有良好的随机性和性能，适用于大多数场景。
- **`std::random_device`**：用于生成非确定性随机数，常用作种子。

## 随机数分布

随机数分布将引擎生成的均匀分布的随机数转换为特定分布的值。C++ 提供了多种分布，常用的包括：

- **均匀分布**
  - `std::uniform_int_distribution`：整数均匀分布
  - `std::uniform_real_distribution`：实数均匀分布

- **正态（高斯）分布**
  - `std::normal_distribution`

- **伯努利分布**
  - `std::bernoulli_distribution`

- **离散分布**
  - `std::discrete_distribution`

- **指数分布**
  - `std::exponential_distribution`

- **其他分布**
  - `std::poisson_distribution`, `std::gamma_distribution`, `std::cauchy_distribution` 等

## 随机数生成的步骤

生成随机数的一般步骤如下：

1. **创建随机数引擎：**
```cpp
std::mt19937 engine(seed);
```
或者使用非确定性种子：
```cpp
std::random_device rd;
std::mt19937 engine(rd());
```
创建随机数分布：
```cpp
std::uniform_int_distribution<int> dist(1, 100);
```
生成随机数：

```cpp
int random_number = dist(engine);
```
### 示例代码
以下是一些常见的随机数生成示例，展示如何结合引擎和分布生成不同类型的随机数。

生成均匀分布的整数
```cpp

#include <iostream>
#include <random>

int main() {
    // 创建一个随机数引擎，使用随机设备作为种子
    std::random_device rd;
    std::mt19937 engine(rd());

    // 定义一个均匀分布，范围从1到100
    std::uniform_int_distribution<int> dist(1, 100);

    // 生成10个随机整数
    for (int i = 0; i < 10; ++i) {
        int random_number = dist(engine);
        std::cout << random_number << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

输出示例：

```
42 17 89 3 56 78 23 65 34 90
```

#### 生成均匀分布的浮点数

```cpp
#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 engine(rd());

    // 定义一个均匀分布，范围从0.0到1.0
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // 生成10个随机浮点数
    for (int i = 0; i < 10; ++i) {
        double random_number = dist(engine);
        std::cout << random_number << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

输出示例：

```
0.37454 0.95071 0.73199 0.59866 0.15602 0.15599 0.05884 0.86618 0.60112 0.70807
```

#### 生成正态分布的随机数

```cpp
#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 engine(rd());

    // 定义一个正态分布，均值为0，标准差为1
    std::normal_distribution<double> dist(0.0, 1.0);

    // 生成10个正态分布的随机数
    for (int i = 0; i < 10; ++i) {
        double random_number = dist(engine);
        std::cout << random_number << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

输出示例：

```
-0.50013 1.76405 0.40183 -1.15038 0.31307 0.18328 -0.85410 0.48213 0.90265 -0.50611
```

#### 生成离散分布的随机数

```cpp
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::random_device rd;
    std::mt19937 engine(rd());

    // 定义离散分布，事件权重分别为1, 2, 3
    std::discrete_distribution<int> dist({1, 2, 3});

    // 生成10个离散分布的随机数
    for (int i = 0; i < 10; ++i) {
        int random_number = dist(engine);
        std::cout << random_number << " "; // 结果为0,1,2，概率分别为1/6, 2/6, 3/6
    }
    std::cout << std::endl;

    return 0;
}
```

输出示例：

```
2 1 2 2 0 1 2 2 1 1
```

## 高级用法

### 自定义随机数引擎和分布

您可以根据需要选择不同的引擎和分布组合。例如，使用 `std::mt19937_64` 引擎和 `std::exponential_distribution` 分布：

```cpp
#include <iostream>
#include <random>

int main() {
    // 使用64位的梅森旋转引擎
    std::random_device rd;
    std::mt19937_64 engine(rd());

    // 定义指数分布，lambda=1.0
    std::exponential_distribution<double> dist(1.0);

    // 生成5个指数分布的随机数
    for (int i = 0; i < 5; ++i) {
        double random_number = dist(engine);
        std::cout << random_number << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

输出示例：

```
0.23456 1.67890 0.12345 2.34567 0.98765
```

### 生成随机序列

如果需要生成一个随机序列，可以结合循环和容器：

```cpp
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    std::vector<int> random_numbers;
    random_numbers.reserve(100); // 预留空间，避免频繁扩展

    for (int i = 0; i < 100; ++i) {
        random_numbers.push_back(dist(engine));
    }

    // 输出前10个随机数
    for (int i = 0; i < 10; ++i) {
        std::cout << random_numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## 注意事项
### 种子选择：

使用 `std::random_device` 作为种子，可以获得更高质量的随机数。但在某些平台上，`std::random_device` 可能不是非确定性的。
如果需要可重复的随机数序列，可以使用固定的种子值：
```cpp
std::mt19937 engine(12345);
```
### 引擎的选择：

不同的引擎有不同的性能和周期长度。`std::mt19937` 是一个平衡性能和随机性的常用选择。
多线程环境：

各线程应使用独立的随机数引擎，以避免竞争条件和状态共享问题。
分布的参数：

确保理解每种分布的参数意义，例如，正态分布的均值和标准差。
性能考虑：

对于高性能需求，选择合适的引擎和分布组合，避免不必要的计算开销。

## 总结

C++ 的 `<random>` 库提供了一套现代化、灵活且强大的随机数生成机制。通过选择合适的随机数引擎和分布，您可以生成各种类型的随机数，满足不同的应用需求。以下是使用 `<random>` 库的一般步骤：

1. 选择并创建一个随机数引擎：
   ```cpp
   std::random_device rd;
   std::mt19937 engine(rd());
   ```
2. 选择并创建一个随机数分布：
   ```cpp
   std::uniform_int_distribution<int> dist(1, 100);
   ```
3. 生成随机数：
   ```cpp
   int random_number = dist(engine);
   ```

通过理解和应用这些基本概念，您可以在 C++ 项目中高效、可靠地生成各种随机数。如果有更复杂的需求，还可以探索更高级的用法和自定义组合.