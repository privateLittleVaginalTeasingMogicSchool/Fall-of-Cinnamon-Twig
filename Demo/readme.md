# 开发说明


## 类型

### 主要类型一览


类名|继承自|说明|
-----|-------|----
*Skill* |-|技能基类，所有技能均继承自此类
*Hero*|-| 角色基类，所有角色均继承自此类
*Subject*|-|战斗状态中的角色，负责技能发出与处理
*AttackRequest*|-|战斗请求，含有技能释放源，技能目标，及技能本身
*Master*|-|负责撮合战斗。接受*AttackRequest*，并派发战斗
*xostream*|*std::ostringstream*|用来实现线程互斥的输出


## 全局变量
变量名 | 变量说明
--------|----------
*Master::master* |负责战斗撮合
*xcout* |线程安全的*std::cout* （eXclusive cout）


## 战斗过程
以 Hero_1 向 Hero_2 发起攻击为例

* Hero_1 线程的视角：

1. Hero_1 + Skill_1 组成本次战斗的 Subject，调用*Subject::SendTo()*方法，调用
2. Subject 使用 Send 方法向 Master 线程发起攻击请求， AttackRequest 线程死亡

  Master 正忙

3. Master 向 Hero_1 发送第一次响应，Hero_1 得到攻击请求是否有效的应答
  
  Hero_2 正忙

4. Hero_2 向 Hero_1 发送第二次响应，Hero_1 得到攻击的结果（攻击是否有效，若有效对 Hero_2 造成伤害的大小等）



* Master 线程的视角：

1. 收到 Hero_1 发来的攻击请求，判断请求是否合规，若有效则将请求压入请求队列，向 Hero_1 发送第一次响应
2. 取出队列顶端的请求，得到攻击目标 Hero_2，使用 Forward 方法向 Hero_2 转发攻击请求


* Hero_2 线程的视角：

1. 收到 Master 转发的攻击请求后，创建独立线程 AttackHandler
2. AttackHandler 根据自身buff、Master转发的攻击请求中的 Skill 及其他信息结算伤害
3. 返回一个包含计算结果的响应给 Hero_1