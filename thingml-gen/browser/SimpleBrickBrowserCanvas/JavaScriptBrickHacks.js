'use strict';

StateJS.internalTransitionsTriggerCompletion = true;

/**
 * Definition for type : JavaScriptBrickHacks
 **/
function JavaScriptBrickHacks(name, root, debug) {

this.name = name;
this.root = (root === null)? this : root;
this.debug = debug;
this.ready = false;
this.bus = new EventEmitter();
//Attributes
this.build(name);
}
//State machine (states and regions)
JavaScriptBrickHacks.prototype.build = function(session) {//optional session name and root instance to fork a new session
this.statemachine = new StateJS.StateMachine('States');
this._initial_JavaScriptBrickHacks_States = new StateJS.PseudoState('_initial', this.statemachine, StateJS.PseudoStateKind.Initial);
let JavaScriptBrickHacks_States_Hack = new StateJS.State('Hack', this.statemachine).entry(() => {

          SimpleBrick.prototype.createBricks = function() {
            this._js_bricks = [];
            for (var y = 0; y < this.SimpleBrick_BRICK_ROWS_var; y++) {
              this._js_bricks[y] = [];
              for (var x = 0; x < 8; x++) {
                this._js_bricks[y][x] = true;
                this.drawBrick(x, y);
              }
            }
          };
          
          SimpleBrick.prototype.bricksLeft = function() {
            var result = 0;
            for (var y = 0; y < this.SimpleBrick_BRICK_ROWS_var; y++) {
              for (var x = 0; x < 8; x++) {
                if (this._js_bricks[y][x]) result += 1;
              }
            }
            return result;
          };
          
          SimpleBrick.prototype.collideBrick = function(xpos, ypos) {
            var bry = Math.floor((ypos-this.SimpleBrick_TOP_var-20*this.SimpleBrick_SCALE_var)/(this.SimpleBrick_BRICK_HEIGHT_var*this.SimpleBrick_SCALE_var));
            var result = false;
            if (bry >= 0 && bry < this.SimpleBrick_BRICK_ROWS_var) {
              var brx = Math.floor((xpos-this.SimpleBrick_LEFT_var)/((this.SimpleBrick_RIGHT_var-this.SimpleBrick_LEFT_var)/8));
              if (this._js_bricks[bry][brx]) {
                this.removeBrick(brx, bry);
                this._js_bricks[bry][brx] = false;
                result = true;
              }
            }
            return result;
          };
        
});
this._initial_JavaScriptBrickHacks_States.to(JavaScriptBrickHacks_States_Hack);
}
//ThingML-defined functions
//Public API for lifecycle management
JavaScriptBrickHacks.prototype._stop = function() {
this.root = null;
this.ready = false;
};

JavaScriptBrickHacks.prototype._delete = function() {
this.statemachine = null;
this.States_instance = null;
this.bus.removeAllListeners();
};

//Public API for third parties
JavaScriptBrickHacks.prototype._init = function() {
this.States_instance = new StateJS.StateMachineInstance("States_instance");
StateJS.initialise(this.statemachine, this.States_instance );
this.ready = true;
};

JavaScriptBrickHacks.prototype._receive = function(msg) {//msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}
if(this.ready){
StateJS.evaluate(this.statemachine, this.States_instance, msg);
} else { setTimeout(()=>this._receive(msg),0) }};
JavaScriptBrickHacks.prototype.toString = function() {
let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
result += '';
return result;
};
