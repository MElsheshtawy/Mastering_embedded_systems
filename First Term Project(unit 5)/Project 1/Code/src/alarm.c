extern short alarmstat;
void check_alarm(){
    if(alarmstat){
        Set_Alarm_actuator(1);
    }
    else{
        Set_Alarm_actuator(0);
    }
}