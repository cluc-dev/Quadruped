// set the names of the servos
/*
frh = front right hip
 frl = front right leg
 flh = front left hip
 fll = front left leg
 rlh = rear left hip
 rll = rear left leg
 rrh = rear right hip
 rrl = rear right leg
 */
 
Servo frh;
Servo frl;
Servo flh;
Servo fll;
Servo rlh;
Servo rll;
Servo rrh;
Servo rrl;
Servo eye;

int home_frh = 80;
int home_frl = 78;
int home_flh = 86;
int home_fll = 90;
int home_rlh = 93;
int home_rll = 82;
int home_rrh = 107;
int home_rrl = 70;

int b;
int x;
int w;
int up;
int up2;
int up3;
int down;
int down2;
int steps;
int rightsteps;
int leftsteps;
int back;
int pos;

void setup()
{
  // assign servos to pins and center servos
  frh.attach(A1);
  frh.write(home_frh);
  frl.attach(A0);
  frl.write(home_frl);
  flh.attach(D1);
  flh.write(home_flh);
  fll.attach(D0);
  fll.write(home_fll);
  rlh.attach(A5);
  rlh.write(home_rlh);
  rll.attach(A4);
  rll.write(home_rll);
  rrh.attach(A7);
  rrh.write(home_rrh);
  rrl.attach(A6);
  rrl.write(home_rrl);

}

void idle() // this is the delay between the steps -> walking speed
{
  delay(200);  // increase this to visualize locomotion easier
}

void flatout()
{
  frh.write(home_frh);
  frl.write(home_frl);
  flh.write(home_flh);
  fll.write(home_fll);
  rlh.write(home_rlh);
  rll.write(home_rll);
  rrh.write(home_rrh);
  rrl.write(home_rrl);
}

void standup()
{
  up2 = 0;
  up3 = 0;
  frh.write(home_frh+30);
  flh.write(home_flh-30);
  rlh.write(home_rlh-30);
  rrh.write(home_rrh+20);
  for(up = 0; up < 80; up++)
  {
    frl.write(home_frl-up);
    up2 = up2 - 1;
    fll.write(home_fll-up2);
    delay(20);
  }

  for(up = 0; up < 90; up++)
  {
    rll.write(home_rll-up);
    up3 = up3 - 1;
    rrl.write(up3+home_rrl);
    delay(15);
  }
}

void sleep()
{
  // hips
  frh.write(home_frh-20);
  flh.write(home_flh);
  rlh.write(home_rlh-20);
  rrh.write(home_rrh);
  // legs
  frl.write(home_frl-90);
  fll.write(home_fll+90);
  rll.write(home_rll-90);
  rrl.write(home_rrl+90);
}

void stand()
{
  frh.write(home_frh-20);
  frl.write(home_frl+80);
  delay(20);
  flh.write(home_flh-10);
  fll.write(home_fll-70);
  delay(20);
  rlh.write(home_rlh-10);
  rll.write(home_rll+80);
  delay(20);
  rrh.write(home_rrh-20);
  rrl.write(home_rrl-70); 
  delay(20);
}

void forward()
{
  // lift front right leg, move front right hip forward and rear right hip backward, lower front right leg
  rll.write(home_rll-50);  // lower the diagonal opposite leg a bit to keep the balance
  frl.write(home_frl-30);  //orig 140
  idle();
  frh.write(home_frh-25);
  rrh.write(home_rrh+60); // orig 90
  idle();
  frl.write(home_frl-80);  //orig 170
  rll.write(home_rll-60);  //orig 170  //put the diagonal opposite leg down to keep the balance
  // lift rear left leg, move rear left hip forward and front right hip backward, lower rear left leg 
  frl.write(home_frl-80);  //orig 140 //lower the diagonal opposite leg a bit to keep the balance
  rll.write(home_rll-50); 
  idle();
  rlh.write(home_rlh+30); //orig 120
  frh.write(home_frh+20);
  idle();
  rll.write(home_rll-60);  // orig 170
  fll.write(home_fll-80);  // put the diagonal opposite leg down to keep the balance
  // lift front left leg, move front left hip forward and rear left hip backward, lower front left leg
  rrl.write(home_rrl-20);  // orig 50  //lower the diagonal opposite leg a bit to keep the balance
  fll.write(home_fll+40);
  idle();
  flh.write(home_flh+40); //orig 110
  rlh.write(home_rlh-50);//orig 60
  idle();
  fll.write(home_fll+70);
  rrl.write(home_rrl-70);  // put the diagonal opposite leg down to keep the balance
  // lift rear right leg, move rear right hip forward and front left hip backward, lower rear right leg 
  fll.write(home_fll+40);  // lower the diagonal opposite leg a bit to keep the balance 
  rrl.write(home_rrl-40); 
  idle();
  rrh.write(home_rrh-40); //orig 30
  flh.write(home_flh-20); //orig 50
  idle();
  rrl.write(home_rrl-50); //orig 20
  fll.write(home_fll+70);  // orig 20 //put the diagonal opposite leg down to keep the balance
  idle();
}

void loop()
{
  //distance = analogRead(sensor);
  flatout();
  delay(2000);
  standup();
  delay(2000);
  forward();
  forward();
  forward();
  forward();
  delay(2000);
}
