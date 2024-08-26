long decode(byte pos){
    read = disk[i++];
    if(pos==0)read = disk[i++],pos=8;
    byte lvl ;
    long output=0;
    long toget = 2;
    if(pos<3){
        if(pos==2) lvl = (3 & read) << 1 , read = disk[i++], lvl = lvl | (1 & (read >> 7)) , pos = 7;  
        else lvl =  (1 & read) << 2 , read = disk[i++] , lvl = lvl | (3 & (read >> 6)), pos = 6;
    } 
    else lvl = 7 & (read >> (pos - 3)), pos-=3;if(!pos)pos=8,read = disk[i++]; 
    while(lvl--){
        output = 0;
        while(toget){
            if(toget<pos){
                output = output | (makeToget(toget) & (read >> (pos-toget)));  
                pos = pos-toget;
                toget = 0;
            }
            else{
                output = output |  (makeToget(pos) & read );
                toget -= pos;
                if(toget>8)output = output << 8;
                else output = output << toget;
                pos = 8;
                read = disk[i++];
            }
        }
        toget = output;
    }
    i--;
    currbit = pos;
    return output;
}


