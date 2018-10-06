2018/10/16              解决虚拟节点分配不均匀问题, murmurhash的使用问题！

2018/10/16              解决初始化段错误问题, 更改如下：
                        void RandIp(char*s){
                          unsigned int ip1 = rand()%255;
                          unsigned int ip2 = rand()%255;
                          unsigned int ip3 = rand()%255;
                          unsigned int ip4 = rand()%255;
                          sprintf(s,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
						}
