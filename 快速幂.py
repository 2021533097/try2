import time

def ti(func):
    def wrapper(*args,**kwargs):
        t1 = time.time()
        ret=func(*args,**kwargs)
        t2=time.time()
        print('用时为: {:.3}'.format(t2-t1))
        return ret
    return wrapper


def len_ex(int_ex):
    a = []
    count = 0
    while (int_ex >= 1):
        c = int_ex % 2
        int_ex = int_ex // 2
        count += 1
        a.append(c)
    return count, a

@ti
def mod(int_bn, int_ex, int_m):
    x = 1
    k, bit = len_ex(int_ex)
    power = int_bn % int_m
    for i in range(k):
        if bit[i] == 1:
            x = (x * power) % int_m
        power = power * power % int_m
    return x
a = 26430018304661698227244889550916468317489455778956328592921983469699792309163665193972706206594036869415691968221117606771494540098970766552365207210568611105852640630040412543297842462434526788081852074542946114404279053789976397875435006094029065093695673255562607050336148424707698012085470002233698228862346738763599120210887024055251199687451392437357330469313875769415203278005429487989371958004062135384988676187092753933346466785135069682592239769739616884935612245424974736666329142491909330198993521032748920319427468193197363789859738402941190883470502934385251934875320122360082927644910373611459923294476
e=14409405982160132058252555071975393865919464165649477935316970889691161917952938338402420626169849869240199817340818785857661040902521177902522865655959315955027296333658575625679171649648237486715107874038848080146760431808160047758267886816563159460881275453304962088598750789947602763231536498803689415008248542306983990585872732303067442760485939483530499206750926623632218337793608305495353477797937055213103722548287089239675029998455237837122665431788486963392282333218897305536581935858534831705616909506614608137265328584496490209976683510539438184418619421230489065033982087166936851293061923363455338233631
n=64543139452648583804777033627501791038942806480746416798824757337964931888296539408775325373896296201833019433336591701850604192958009038518829207716785069084776737389127085606861435151087914978789508354621086437098048489783165288663090667930959738070532371062440986402482696167926970371372070378265809277766155735077364001364843786628965534680520817227913435893489039438222319565950285009689464886596531381136997433211960842826747978689934063604682788246549928760755145469051762866022916315234333425333466441336354964665001026523519003032764174124744508998760069425321286184310908109489080474275209430911312055696378
if __name__ == "__main__":
    x=mod(a,e,n)
    print(x)