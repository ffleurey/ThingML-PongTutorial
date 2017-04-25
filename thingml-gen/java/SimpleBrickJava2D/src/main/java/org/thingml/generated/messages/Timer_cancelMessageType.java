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

public class Timer_cancelMessageType extends EventType {
public Timer_cancelMessageType(short code) {super("timer_cancel", code);
}

public Timer_cancelMessageType() {
super("timer_cancel", (short) 0);
}

public Event instantiate(final int id) { return new Timer_cancelMessage(this, id); }
@Override
public Event instantiate(Map<String, Object> params) {return instantiate((Integer) params.get("id"));
}

public class Timer_cancelMessage extends Event implements java.io.Serializable {

public final int id;
@Override
public String toString(){
return "timer_cancel (" + "id: " + id + ")";
}

protected Timer_cancelMessage(EventType type, final int id) {
super(type);
this.id = id;
}
@Override
public Event clone() {
return instantiate(this.id);
}}

}

