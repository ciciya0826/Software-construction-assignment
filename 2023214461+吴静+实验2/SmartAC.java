public class SmartAC extends SmartDevice {
    private int temperature;
    private String mode;

    public SmartAC(String id, String name) {
        super(id, name);
        this.temperature = 26;
        this.mode = "制冷";
    }

    public void setTemperature(int temp) {
        this.temperature = temp;
        System.out.println("空调温度设置为" + temp + "°C");
    }

    public void setMode(String mode) {
        this.mode = mode;
        System.out.println("空调模式设置为" + mode);
    }

    @Override
    public String getDeviceType() {
        return "智能空调";
    }
}
