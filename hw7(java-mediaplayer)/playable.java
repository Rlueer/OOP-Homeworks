public interface playable {
    // Indicates that an object is playable.
    public void play();

    // Retrieves the name of the playable entity.
    public String getName();

    // Retrieves the dimension of the playable entity.
    public String getDimension();

    // Retrieves the duration of the playable entity.
    public String getDuration();

    // Retrieves other information about the playable entity.
    public String getOther();

    // Retrieves the type of the playable entity.
    public String getType();

    // Displays information about the playable entity.
    public void info();

}