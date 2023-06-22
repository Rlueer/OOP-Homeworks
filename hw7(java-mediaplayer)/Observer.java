public interface Observer {
    // Displays the list.
    public void show_list();

    // Moves to the next element of a specified type.
    public void next(String ty);

    // Moves to the previous element of a specified type.
    public void previous(String ty);

    // Adds a base object to the list.
    public void add_base(Base x);

    // Removes a base object from the list.
    public void remove_base(Base x);

    // Displays information about the observer.
    public void info();

    // Clears the array or list of elements.
    public void clear_array();

    // Retrieves the type of the observer.
    public String getTyp();
}
