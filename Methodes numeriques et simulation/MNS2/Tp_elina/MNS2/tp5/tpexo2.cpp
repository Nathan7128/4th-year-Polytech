real T=36000;
int N=1000;
real Tf = 72*3600;
real dt = Tf/N;
int C=99;
real cpu = clock();





// Définition des bordures pour une couronne coupée
border C0(t=0, pi){x=cos(t); y=sin(t);}  
border C1(t=pi, 0){x=0.4*cos(t); y=0.4*sin(t);} 
border C2(t=0.4, 1){x=t; y=0;} 
border C3(t=0, 0.6){x=-1+t; y=0;} 

plot(C0(100) + C1(40) + C2(20) + C3(20),wait=true);
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