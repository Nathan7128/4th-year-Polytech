real T=4;
real dt = 10e-2;
int C=99;
real cpu = clock();





// Définition des bordures pour une couronne coupée
border C0(t=0, pi){x=cos(t); y=sin(t);}  
border C1(t=pi, 0){x=0.4*cos(t); y=0.4*sin(t);} 
border C2(t=0.4, 1){x=t; y=0;} 
border C3(t=0, 0.6){x=-1+t; y=0;} 

plot(C0(50) + C1(20) + C2(10) + C3(10),wait=true);
mesh Th = buildmesh(C0(50) + C1(20) + C2(10) + C3(10)); // Construction du maillage

plot(Th, wait=true); // Affichage du maillage



// Function spaces
fespace Uh(Th, P1b);  // P1b pour la vitesse
Uh u, v, uu, vv;

fespace Ph(Th, P1);   // P1 pour la pression
Ph p, pp;

func f1 = x^2-1.4*x+0.4;
func f2 = -x^2-1.4*x-0.4;

// Problem
solve stokes ([u, v, p], [uu, vv, pp])
    = int2d(Th)(
        dx(u)*dx(uu)
        + dy(u)*dy(uu)
        + dx(v)*dx(vv)
        + dy(v)*dy(vv)
        + dx(p)*uu
        + dy(p)*vv
        + pp*(dx(u) + dy(v))
        - 1e-10*p*pp
    )
    +on(C1,u=0,v=0)
    +on(C0,u=0,v=0)
    + on(C2, u=0, v=f1)
    + on(C3, u=0, v=f2);

// Plot results
plot([u, v], p, wait=1);


//definition du champ de vitesse

func v1 = u;
func v2 = v;

// Fonction de x et de y
func f=S*(.85<=x)*(x<=.95)*(.85<=y)*(y<=.95);

// Condition initiale
func u0=Text + 15*sin(x*3.14)*sin(y*3.14);

// Definition de l'espace des elements finis P1 associe au maillage Th
fespace Vh(Th, P1);

// uh et vh sont des elements de Vh
Vh uh=u0, vh, uold;

problem thermic(uh, vh, solver=LU)=int2d(Th)(vh*uh/dt) 
- int2d(Th)(vh*uold/dt)
+ int2d(Th)(dx(uh)*v1*vh+dy(uh)*vh*v2)
+ int2d(Th)((dx(uh)*dx(vh)+dy(uh)*dy(vh)))
+on(C3,uh=1) + on(C0,uh=0) + on(C1,uh=0) +on(C2,uh=0)
;

int nbval=14;
real[int] valeurs(nbval);
real valmin = -0.1, valmax=1.2;
for(int i=0; i<nbval:i++){valeurs[i]=valmin+i*(valmax-valmin)/(nbval-1);}
for (real t=0; t<T; t+=dt) {
    uold=uh;
    thermic;
    plot(uh, wait=false, value=1, fill=true, viso=valeurs, cmm"t="+t);
}