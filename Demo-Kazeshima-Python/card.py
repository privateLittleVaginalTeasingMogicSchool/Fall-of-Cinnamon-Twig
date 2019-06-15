# KazeshimaAya@gmail.com
# 03.13.2017 UTC
# A simple relization of idea.

from math import pow as power

class Hero:
    'Class of Hero card. Dinstinct hero has fixed Chuang, Zhi and Fu properties'
    Name = ''
    Chuang = 0
    Zhi = 0
    Fu = 0
    MaxFanNum = 1 # The number of fans is HP
    BaseAtk = 1
    BaseDef = 1
    BaseRep = 1 # Reputation is Mana. If a hero wants to use magic attack, typically an evil and dispicable behavior, it will consume his reputation. Of course this will also influence FanNum in most situations.
    CyberAge = 0 # unit of CyberAge is 3 months
    
    def __init__(self, initCyberAge = 0, genChuang, genZhi, genFu, name = ''):
        self.Chuang = genChuang
        self.Zhi = genZhi
        self.Fu = genFu
        self.Name = name
        CA = self.CyberAge
        self.MaxFanNum = CA*genFu*1000 + CA*genZhi*750 + CA*genChuang*550# Simple growth curve. Linear dependence on CyberAge(hero's level)
        self.BaseAtk = CA*genFu*80 + CA*genZhi*120 + CA*genChuang*200 # unbalanced values. Linear growth
        self.BaseDef = CA*genFu*160 + CA*genZhi*200 + CA*genChuang*100 # unbalanced. Linear
        self.BaseRep = CA*genFu*80 + CA*genZhi*60 + CA*genChuang*160 # unbalanced. Linear
        self.BattleStatus = Status(self)

class Status:
    'Class of the temporary status of a hero card. Used in computation during battle'
    CurrentFanNum = 1
    CurrentAtk = 1
    CurrentDef = 1
    CurrentRep = 1
    
    ChuangBar = 0
    ZhiBar = 0 
    FuBar = 0
    MAX_BAR = 
    
    SkillReady1 = False
    SkillReady2 = False
    SkillReady3 = False
    
    BarNormalization = 1
    
    def __init__(self, card):
        self.CurrentFanNum = card.BaseFanNum
        self.CurrentAtk = card.BaseAtk
        self.CurrentDef = card.BaseDef
        self.CurrentRep = card.BaseRep
        self.BarNormalization = power(card.Zhi*card.Chuang*card.Fu,1.0/3)
    
    def barUpdate(self, card):
        if ChuangBar <= MAX_BAR:
            ChuangBar += int(MAX_BAR*card.Chuang/(5.0*BarNormalization))
            if ChuangBar > MAX_BAR:
            ChuangBar = MAX_BAR
        if ZhiBar <= MAX_BAR:
            
