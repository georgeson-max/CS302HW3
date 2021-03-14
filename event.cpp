Event::Event(){
    type = "";
    time = 0;
    length = 0;
}

Event::Event(string newType, int newtime, int newLength){
    type = newType;
    time = newtime;
    length = newLength;
}


string Event::getType() const{
    return type;
}

int Event::getTime() const{
    return time;
}

int Event::getLength() const{
    return length;
}


void Event::setType(string newType){
    type = newType;
}

void Event::setTime(int newtime){
    time = newtime;
}

void Event::setLength(int newLength){
    length = newLength;
}


bool Event::operator<(const  Event& rhs){
    if(time < rhs.time){
        return true;
    }else if(time == rhs.time && type == "Arrival"){
        return true;
    }else{
        return false;
    }

}