/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated.messages;

import org.thingml.java.*;
import org.thingml.java.ext.*;

import org.thingml.generated.api.*;
import java.util.*;
import java.nio.*;

public class NextLevelMessageType extends EventType {
public NextLevelMessageType(short code) {super("nextLevel", code);
}

public NextLevelMessageType() {
super("nextLevel", (short) 0);
}

public Event instantiate() { return new NextLevelMessage(this); }
@Override
public Event instantiate(Map<String, Object> params) {return instantiate();
}

public class NextLevelMessage extends Event implements java.io.Serializable {

@Override
public String toString(){
return "nextLevel (" + ")";
}

protected NextLevelMessage(EventType type) {
super(type);
}
@Override
public Event clone() {
return instantiate();
}}

}

