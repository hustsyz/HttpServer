# 测试

## 测试环境

- OS：Ubuntu 18.04.3 LTS
- 内存：8G
- CPU：i7-5600U CPU

## 测试方法

- 选择本地环境测试
- 使用工具Webbench，测试500个客户端，访问30s.
- 线程池开启4线程

## 测试结果

- WebServer 不关闭LOG连接测试

![2020-07-24 23-52-49屏幕截图.png](https://i.loli.net/2020/07/25/NPsnB1azlGvuUwx.png)

开启LOG，磁盘IO对测试结果有影响

- WebServer 关闭LOG连接测试

![2020-07-25 00-01-15屏幕截图.png](https://i.loli.net/2020/07/25/s6Ml8ZFX3DzNjh2.png)

速度略有提高

CPU负载

![2020-07-24 23-58-27屏幕截图.png](https://i.loli.net/2020/07/25/w5kUFfVesj8o2OP.png)s
