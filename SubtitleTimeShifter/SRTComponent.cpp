#include "SRTComponent.h"

SRTComponent::SRTComponent(int _id, Time _begin, Time _end, string _text) {
	
	setID(_id);
	setBegin(_begin);
	setEnd(_end);
	setText(_text);

}

SRTComponent::SRTComponent() {

}