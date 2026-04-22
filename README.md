

# 仙剑

基于palsdl、pal-harmony等项目开发的鸿蒙版本

<!-- PROJECT SHIELDS -->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />

<p align="center">
  <a href="https://gitcode.com/funbocchi/pal_ohos/">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">仙剑——鸿蒙版</h3>
  <p align="center">
    基于源项目开源代码的C++重构优化版本
    <br />
    <a href="https://gitcode.com/funbocchi/pal_ohos"><strong>探索本项目的文档 »</strong></a>
    <br />
    <br />
    <a href="https://gitcode.com/funbocchi/pal_ohos">查看Demo</a>
    ·
    <a href="https://gitcode.com/funbocchi/pal_ohos/issues">报告Bug</a>
    ·
    <a href="https://gitcode.com/funbocchi/pal_ohos/issues">提出新特性</a>
  </p>

</p>


 
## 目录
- [开发概述](#开发概述)
  - [调整和优化的部分](#调整和优化部分)
- [上手指南](#上手指南)
  - [开发前的配置要求](#开发前的配置要求)
  - [安装步骤](#安装步骤)
- [文件目录说明](#文件目录说明)
- [开发的架构](#开发的架构)
- [部署](#部署)
- [使用到的框架](#使用到的框架)
- [贡献者](#贡献者)
  - [如何参与开源项目](#如何参与开源项目)
- [版本控制](#版本控制)
- [作者](#作者)
- [鸣谢](#鸣谢)

### 开发概述



###### 调整和优化部分

1. 源项目是基于C语言进行整体构造的，从结构上看，虽然使用了结构体对变量进行包裹，但是整体存储是放在全局空间当中，比较复杂，类似的还有方法也是如此。出于对源项目代码进行解耦的想法，在开发过程中对上述的结构体、方法进行了进一步封装，通过目录进行区分。
2. 源项目中声明了大量的类型别名，开发过程中对此进行了一定的删减。并使用cstdint提供的类型别名进行替代。
3. 对于部分结构体中使用到的，已存在对应结构体但仍然使用基础类型进行声明的部分，考虑到源项目采取swap的方式对此类变量进行赋值，在不改变本原则的前提下进行了一定优化。

### 上手指南



###### 开发前的配置要求

1. xxxxx x.x.x
2. xxxxx x.x.x

###### **安装步骤**

1. Get a free API Key at [https://example.com](https://example.com)
2. Clone the repo

```sh
git clone https://gitcode.com/funbocchi/pal_ohos.git
```

### 文件目录说明
eg:

```
pal_ohos/
├── classes/
│   ├── CMakeLists.txt
│   ├── include/
│   │   ├── src/
│   │   ├── bridge/
│   │   ├── engine/
│   │   └── util/
│   ├── src/
│   ├── bridge/
│   │   ├── CMakeLists.txt
│   │   ├── XComponentBridgeRegistry.cpp
│   │   ├── XComponentBridgeRegistry.h
│   │   ├── GameEngineBridge.cpp
│   │   └── GameEngineBridge.h
│   ├── engine/
│   │   ├── CMakeLists.txt
│   │   ├── battle.cpp
│   │   ├── script.cpp
│   │   ├── map.cpp
│   │   └── include/
│   │       ├── battle.h
│   │       ├── script.h
│   │       └── map.h
│   └── util/
│       ├── CMakeLists.txt
│       ├── util.cpp
│       └── include/
│           └── util.h
│
├── product/
│   └── laptop/
│       └── src/main/cpp/
│           ├── CMakeLists.txt
│           └── napi_init.cpp
│
└── CMakeLists.txt

```





### 开发的架构 

请阅读[ARCHITECTURE.md](https://gitcode.com/funbocchi/pal_ohos/blob/master/ARCHITECTURE.md) 查阅为该项目的架构。

### 部署

暂无

### 使用到的框架

- [xxxxxxx](https://getbootstrap.com)
- [xxxxxxx](https://jquery.com)
- [xxxxxxx](https://laravel.com)

### 贡献者

请阅读**CONTRIBUTING.md** 查阅为该项目做出贡献的开发者。

#### 如何参与开源项目

贡献使开源社区成为一个学习、激励和创造的绝佳场所。你所作的任何贡献都是**非常感谢**的。


1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



### 版本控制

该项目使用Git进行版本管理。您可以在repository参看当前可用版本。

### 作者

xxx@xxxx

知乎:xxxx  &ensp; qq:xxxxxx    

 *您也可以在贡献者名单中参看所有参与该项目的开发者。*

### 版权说明

该项目签署了MIT 授权许可，详情请参阅 [LICENSE.txt](https://gitcode.com/funbocchi/pal_ohos/blob/master/LICENSE.txt)

### 鸣谢


- [GitHub Emoji Cheat Sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet)
- [Img Shields](https://shields.io)
- [Choose an Open Source License](https://choosealicense.com)
- [GitHub Pages](https://pages.github.com)
- [Animate.css](https://daneden.github.io/animate.css)
- [xxxxxxxxxxxxxx](https://connoratherton.com/loaders)

<!-- links -->
[your-project-path]:shaojintian/Best_README_template
[contributors-shield]: https://img.shields.io/github/contributors/shaojintian/Best_README_template.svg?style=flat-square
[contributors-url]: https://gitcode.com/funbocchi/pal_ohos/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/shaojintian/Best_README_template.svg?style=flat-square
[forks-url]: https://gitcode.com/funbocchi/pal_ohos/network/members
[stars-shield]: https://img.shields.io/github/stars/shaojintian/Best_README_template.svg?style=flat-square
[stars-url]: https://gitcode.com/funbocchi/pal_ohos/stargazers
[issues-shield]: https://img.shields.io/github/issues/shaojintian/Best_README_template.svg?style=flat-square
[issues-url]: https://img.shields.io/github/issues/shaojintian/Best_README_template.svg
[license-shield]: https://img.shields.io/github/license/shaojintian/Best_README_template.svg?style=flat-square
[license-url]: https://gitcode.com/funbocchi/pal_ohos/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/shaojintian







### 简简简简述

本项目基于palsdl、pal-harmony等修改而来，目前处于新建文件夹阶段

#### 备忘录

项目中采用同字节大小的类型进行相互的转换使用，通常为unsigned short及short等两字节为元的类型

当前优化保留了这一特性，并考虑加入转换来提高代码的可读性


#### 目录结构
```
pal_ohos/
├── classes/
│   ├── CMakeLists.txt
│   ├── include/
│   │   ├── src/
│   │   ├── bridge/
│   │   ├── engine/
│   │   └── util/
│   ├── src/
│   ├── bridge/
│   │   ├── CMakeLists.txt
│   │   ├── XComponentBridgeRegistry.cpp
│   │   ├── XComponentBridgeRegistry.h
│   │   ├── GameEngineBridge.cpp
│   │   └── GameEngineBridge.h
│   ├── engine/
│   │   ├── CMakeLists.txt
│   │   ├── battle.cpp
│   │   ├── script.cpp
│   │   ├── map.cpp
│   │   └── include/
│   │       ├── battle.h
│   │       ├── script.h
│   │       └── map.h
│   └── util/
│       ├── CMakeLists.txt
│       ├── util.cpp
│       └── include/
│           └── util.h
│
├── product/
│   └── laptop/
│       └── src/main/cpp/
│           ├── CMakeLists.txt
│           └── napi_init.cpp
│
└── CMakeLists.txt
```