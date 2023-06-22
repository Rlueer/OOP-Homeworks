import java.util.ArrayList;

public class Dataset{
    private ArrayList<Observer> observers;   // ArrayList to store Observer objects
    private ArrayList<Base> objects;    // ArrayList to store Base objects

    public Dataset(){
        observers = new ArrayList<>();  // Initialize the observers ArrayList
        objects = new ArrayList<>();    // Initialize the objects ArrayList
    }
    public void add(Base x){
        objects.add(x); // Add the Base object to the objects ArrayList

        // Iterate through each Observer in the observers ArrayList
        for(Observer Observer: observers){
            // Check the type of the Observer
            if(Observer.getTyp()=="player"){
                // Check the type of the Base object
                if(x.getType()=="video" || x.getType()=="audio"){
                    Observer.add_base(x);// Add the Base object to the Observer
                }
            }
            else if(Observer.getTyp()=="viewer"){
                // Check the type of the Base object
                if(x.getType()=="image" || x.getType()=="text"){
                    Observer.add_base(x);// Add the Base object to the Observer
                }
            } 
        }
    }
    public void remove(Base x){
        try{
            if(objects.size()==0){
                throw new RuntimeException("Cant remove object size is 0");
            }
        }catch(RuntimeException e){
            System.out.println("Exception caught: " + e.getMessage());
        }
        objects.remove(x);// Remove the Base object from the objects ArrayList
        for(Observer Observer: observers){
            // Check the type of the Observer
            if(Observer.getTyp()=="player"){
                // Check the type of the Base object
                if(x.getType()=="video" || x.getType()=="audio"){
                    Observer.remove_base(x);// Remove the Base object from the Observer
                }
            }
            else if(Observer.getTyp()=="viewer"){
                // Check the type of the Base object
                if(x.getType()=="image" || x.getType()=="text"){
                    Observer.remove_base(x);// Remove the Base object from the Observer
                }
            } 
        }
    }
    public void printAll() {
        // Iterate through each Base object in the objects ArrayList
        for (Base bas : objects) {
            System.out.println("Name: " + bas.getName());
            System.out.println("Dimension: " + bas.getDimension());
            System.out.println("Duration: " + bas.getDuration());
            System.out.println("Other: " + bas.getOther());
            System.out.println("---------------------------");
        }
    }
    public void register_obs(Observer asd){
        observers.add(asd);// Add the Observer object to the observers ArrayList
        // Iterate through each Base object in the objects ArrayList
        for (Base bas : objects){
            for(Observer Observer: observers){
                // Check the type of the Observer
                if(Observer.getTyp()=="player"){
                     // Check the type of the Base object
                    if(bas.getType()=="video" || bas.getType()=="audio"){
                        Observer.add_base(bas);// Add the Base object to the Observer
                    }
                }
                else if(Observer.getTyp()=="viewer"){
                    // Check the type of the Base object
                    if(bas.getType()=="image" || bas.getType()=="text"){
                    Observer.add_base(bas);// Add the Base object to the Observer
                    }
                } 
            }   
        }
    }
    public void remove_obs(Observer asd){
        observers.remove(asd);  // Remove the Observer object from the observers ArrayList
        asd.clear_array();  // Clear the array of the Observer object
    }
    
    public static void main(String args[]){
        //This is our dataset. We have only one dataset.
    Dataset ds = new Dataset();
    //Lets create different observers.
    Player p1 = new Player();
    Player p2 = new Player();
    Viewer v1 = new Viewer();
    Viewer v2 = new Viewer();
    
    ds.register_obs(p1);
    ds.register_obs(p2);
    ds.register_obs(v1);
    ds.register_obs(v2);

    ds.add(new Image("imagename1", "dimension info1", "other info1"));
    ds.add(new Image("imagename2", "dimension info2", "other info2"));
    ds.add(new Image("imagename3", "dimension info3", "other info3"));
    ds.add(new Image("imagename4", "dimension info4", "other info4"));
    ds.add(new Image("imagename5", "dimension info5", "other info5"));
    ds.add(new Audio("audioname1", "duration1", "other info1"));
    ds.add(new Audio("audioname2", "duration2", "other info2"));
    ds.add(new Audio("audioname3", "duration3", "other info3"));
    ds.add(new Video("videoname1", "duration1", "other info1"));
    ds.add(new Video("videoname2", "duration2", "other info2"));
    ds.add(new Video("videoname3", "duration3", "other info3"));
    ds.add(new Text("textname1", "other info1"));
    ds.add(new Text("textname2", "other info2"));
    ds.add(new Text("textname3", "other info3"));

    playable po = p1.currently_playing();
    
    po.info();
    p1.previous("video");
    p1.previous("audio");
    p1.previous("text");

    ds.remove((Base)po);

    non_playable np = v1.currently_viewing();
    np.info(); 

    System.out.println("111111111111111111111111111111111111111111");
    System.out.println("\n\n\n");

    p1.show_list();
    
    System.out.println("111111111111111111111111111111111111111111");
    System.out.println("\n\n\n");
    
    v1.show_list();

    }
}
