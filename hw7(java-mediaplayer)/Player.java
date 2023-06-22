import java.util.ArrayList;

public class Player implements Observer{
    private ArrayList<playable> playlist;
    int index;
    public Player(){
        playlist = new ArrayList<>();
        index=0;
    }
    public void show_list(){
        // Iterate over the playlist and print information about each item
        // such as name, dimension, duration, and other details
        for(playable play : playlist) {
            System.out.println("Name: " + play.getName());
            System.out.println("Dimension: " + play.getDimension());
            System.out.println("Duration: " + play.getDuration());
            System.out.println("Other: " + play.getOther());
            System.out.println("---------------------------");
        }
    }
    // Returns the currently playing item in the playlist
    public playable currently_playing(){
        //it prints same last or first object if cant go next or previous
        return playlist.get(index);
    }
    // Plays the next item in the playlist of the given type (audio or video)
    public void next(String ty){
        // Move to the next item of the specified type in the playlist
        try{
            if(!ty.equals("audio") && !ty.equals("video")){
                throw new RuntimeException("Player can only work with audio and video");
            }
            else if(playlist.size()==0){
                throw new RuntimeException("Can't go to next.Playlist size is 0");
            }
            else if(playlist.size()-1==index){
                throw new RuntimeException("Can't go to next. end of Playlist");
            }
            else{
                int flag=0;
                while(currently_playing().getType()!=ty){//ty tipinden bulana kadar ilerliyor
                    if(index==playlist.size()-1){
                        System.out.println("Couldnt find next "+ty+".Playlist ended");
                        flag=1;
                        break;
                    }
                    index++;
                }
                if(flag==0){
                    //System.out.println(index+" "+currently_playing().getType());
                }
                else{
                    index++;
                }
            }
        }catch(RuntimeException e){
            System.out.println("Exception caught: " + e.getMessage());
        }

    }
    // Move to the previous item of the specified type in the playlist
    public void previous(String ty) {
        try {
            if(!ty.equals("audio") && !ty.equals("video")){
                throw new RuntimeException("Player can only work with audio and video");
            }
            else if(playlist.size() == 0) {
                throw new RuntimeException("Can't go to previous. Playlist size is 0.");
            }
            else if(index == 0) {
                throw new RuntimeException("Can't go to previous. Already at the beginning of the playlist.");
            } 
            else{
                int flag = 0;
                while (currently_playing().getType() != ty) {
                    if (index == 0) {
                        System.out.println("Couldn't find previous " + ty + ". Already at the beginning of the playlist.");
                        flag = 1;
                        break;
                    }
                    index--;
                }
                if (flag == 0) {
                    //System.out.println(index + " " + currently_playing().getType());
                }
                else{
                    index--;
                }
            }
        } catch (RuntimeException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
    public void add_base(Base x){
        // Add a playable item to the playlist
        playlist.add((playable)x);
    }
    public void remove_base(Base x){
        // Remove a playable item from the playlist
        if(currently_playing().getName()==x.getName()){
            index++;
        }
        try{
            if(index>playlist.size()-1){
                throw new RuntimeException("There is no item after removed cant go next");
            }
            if(playlist.size()==0){
                throw new RuntimeException("Cant remove object size is 0");
            }
        }catch(RuntimeException e){
            System.out.println("Exception caught: " + e.getMessage());
        }
        playlist.remove((playable)x);
    }
    public void info(){
        // Display the information of the currently playing item
        System.out.println("Currently playing info:");
        System.out.println("Name: " + currently_playing().getName());
        System.out.println("Duration: " + currently_playing().getDuration());
        System.out.println("Other: " + currently_playing().getOther());
        System.out.println("Dimension: " + currently_playing().getDimension());
        System.out.println("---------------------------");
    }
    public void clear_array(){
        // Clear the playlist
        playlist.clear();
    }
    public String getTyp(){
        // Get the type of the observer (player)
        return "player";
    }

}