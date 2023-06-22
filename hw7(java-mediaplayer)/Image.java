public class Image extends Base implements non_playable,visual{

public Image(String imagename,String idimension,String iother){
    // Constructor for creating an Image object
    // Sets the type, name, duration, other, and dimension of the image
    this.type="image";
    this.name=imagename;
    this.dimension=idimension;
    this.other=iother;
    this.duration="none";
}
// Retrieves the name of the image
public String getName(){
return name;
}
// Retrieves the dimension of the image
public String getDimension(){
    return dimension;
}
// Retrieves the duration of the image
public String getDuration(){
    return duration;
}
// Retrieves other information about the image
public String getOther(){
    return other;
}
// Retrieves the type of the image
public String getType(){
    return type;
}
// Displays information about the image
public void info(){
    System.out.println("Info:");
    System.out.println("Name: " + name);
    System.out.println("Duration: " + duration);
    System.out.println("Other: " + other);
    System.out.println("Dimension: " + dimension);
    System.out.println("---------------------------");
}

};