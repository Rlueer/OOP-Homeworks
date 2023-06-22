import java.util.ArrayList;

class Dataset{
    private ArrayList<Observer> observers;
    private ArrayList<Base> objects;

    public Dataset(){
        observers = new ArrayList<>();
        objects = new ArrayList<>();
    }
    public void add(Base x){
        objects.add(x);
        for(Observer Observer: observers){//OBSERVE EKLENDİKTEN SONRA BU ALTA GİRİYOR YOKSA DİREKT ÜST
            if(Observer.getTyp()=="player"){
                if(x.getType()=="video" || x.getType()=="audio"){
                    Observer.add_base(x);
                }
            }
            else if(Observer.getTyp()=="viewer"){
                if(x.getType()=="image" || x.getType()=="text"){
                    Observer.add_base(x);
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
        objects.remove(x);
        for(Observer Observer: observers){
            if(Observer.getTyp()=="player"){
                if(x.getType()=="video" || x.getType()=="audio"){
                    Observer.remove_base(x);
                }
            }
            else if(Observer.getTyp()=="viewer"){
                if(x.getType()=="image" || x.getType()=="text"){
                    Observer.remove_base(x);
                }
            } 
        }
    }
    public void printAll() {
        for (Base bas : objects) {
            System.out.println("Name: " + bas.getName());
            System.out.println("Dimension: " + bas.getDimension());
            System.out.println("Duration: " + bas.getDuration());
            System.out.println("Other: " + bas.getOther());
            System.out.println("---------------------------");
        }
    }
    public void register_obs(Observer asd){
        observers.add(asd);
        for (Base bas : objects){
            for(Observer Observer: observers){
                if(Observer.getTyp()=="player"){
                    if(bas.getType()=="video" || bas.getType()=="audio"){
                        Observer.add_base(bas);
                    }
                }
                else if(Observer.getTyp()=="viewer"){
                    if(bas.getType()=="image" || bas.getType()=="text"){
                    Observer.add_base(bas);
                    }
                } 
            }   
        }
    }
    public void remove_obs(Observer asd){
        observers.remove(asd); 
        asd.clear_array();
    }
    
    public static void main(String args[]){
        Dataset ds = new Dataset();

        ds.add(new Audio("audioname3", "duration3", "other info3"));
        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Text("textname3", "other info3"));
        ds.add(new Video("videoname12", "duration1", "other info1"));
        
        Dataset x = new Dataset();
        
        Player y = new Player();
        x.register_obs(y);
        y.next("video");
        y.next("video");
        y.next("video");
        
        playable po = y.currently_playing();
        po.info();
        System.out.println("11111111\n\n");
        y.previous("video");
        po = y.currently_playing();
        po.info();
        System.out.println("22222222222\n\n");
        y.previous("audio");
        po = y.currently_playing();
        po.info();
        System.out.println("3333333333\n\n");
        y.previous("video");
        po = y.currently_playing();
        po.info();
        System.out.println("4444444444\n\n");
        y.previous("video");
        po = y.currently_playing();
        po.info();
        y.next("video");
        po = y.currently_playing();
        po.info();
        x.remove((Base)po);


        y.show_list();
        System.out.println("555555555555\n\n");
        
    
}
}
