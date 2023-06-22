public interface visual {
    // Retrieves the name of the visual entity.
    public String getName();

    // Retrieves the dimension of the visual entity.
    public String getDimension();

    // Retrieves the duration of the visual entity.
    public String getDuration();

    // Retrieves other information about the visual entity.
    public String getOther();

    // Retrieves the type of the visual entity.
    public String getType();

    // Displays information about the visual entity.
    public void info();
}