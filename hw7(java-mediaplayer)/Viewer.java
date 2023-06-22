import java.util.ArrayList;

public class Viewer implements Observer{
    private ArrayList<non_playable> viewlist;
    int index;
    public Viewer(){
        viewlist = new ArrayList<>();
        index=0;
    }
    public void show_list(){
        // Iterate over the playlist and print information about each item
        // such as name, dimension, duration, and other details
        for(non_playable view : viewlist) {
            System.out.println("Name: " + view.getName());
            System.out.println("Dimension: " + view.getDimension());
            System.out.println("Duration: " + view.getDuration());
            System.out.println("Other: " + view.getOther());
            System.out.println("---------------------------");
        }
    }
    // Returns the currently playing item in the playlist
    public non_playable currently_viewing(){
        //it prints same last or first object if cant go next or previous
        return viewlist.get(index);
    }
    // Plays the next item in the playlist of the given type (audio or video)
    public void next(String ty){
        // Move to the next item of the specified type in the playlist
        try{
            if(!ty.equals("image") && !ty.equals("text")){
                throw new RuntimeException("Player can only work with image and text");
            }
            else if(viewlist.size()==0){
                throw new RuntimeException("Can't go to next.Viewlist size is 0");
            }
            else if(viewlist.size()-1==index){
                throw new RuntimeException("Can't go to next. end of Viewlist");
            }
            else{
                int flag=0;
                while(currently_viewing().getType()!=ty){//ty tipinden bulana kadar ilerliyor
                    if(index==viewlist.size()-1){
                        System.out.println("Couldnt find next "+ty+".Viewlist ended");
                        flag=1;
                        break;
                    }
                    index++;
                }
                if(flag==0){
                    //System.out.println(index+" "+currently_viewing().getType());
                }
                else{
                    index++;
                }
            }
        }catch(RuntimeException e){
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
    public void previous(String ty) {
        // Move to the previous item of the specified type in the playlist
        try {
            if(!ty.equals("image") && !ty.equals("text")){
                throw new RuntimeException("Player can only work with image and text");
            }
            else if(viewlist.size() == 0) {
                throw new RuntimeException("Can't go to previous. Viewlist size is 0.");
            }
            else if(index == 0) {
                throw new RuntimeException("Can't go to previous. Already at the beginning of the viewlist.");
            } 
            else{
                int flag = 0;
                while (currently_viewing().getType() != ty) {
                    if (index == 0) {
                        System.out.println("Couldn't find previous " + ty + ". Already at the beginning of the viewlist.");
                        flag = 1;
                        break;
                    }
                    index--;
                }
                if (flag == 0) {
                    System.out.println(index + " " + currently_viewing().getType());
                }
                else{
                    index--;
                }
            }
        } catch (RuntimeException e) {
           //System.out.println("Exception caught: " + e.getMessage());
        }
    }
    public void add_base(Base x){
        // Add a playable item to the playlist
        viewlist.add((non_playable)x);
    }
    public void remove_base(Base x){
        // Remove a playable item from the playlist
        if(currently_viewing().getName()==x.getName()){
            index++;
        }
        try{
            if(index>viewlist.size()-1){
                throw new RuntimeException("Index size passed viewlist size");
            }
            if(viewlist.size()==0){
                throw new RuntimeException("Cant remove object size is 0");
            }
        }catch(RuntimeException e){
            System.out.println("Exception caught: " + e.getMessage());
        }
        viewlist.remove((non_playable)x);
    }
    public void info(){
        // Display the information of the currently playing item
        System.out.println("Currently viewing info:");
        System.out.println("Name: " + currently_viewing().getName());
        System.out.println("Duration: " + currently_viewing().getDuration());
        System.out.println("Other: " + currently_viewing().getOther());
        System.out.println("Dimension: " + currently_viewing().getDimension());
        System.out.println("---------------------------");
    }
    public void clear_array(){
        // Clear the playlist
        viewlist.clear();
    }
    public String getTyp(){
        // Get the type of the observer (player)
        return "viewer";
    }

}