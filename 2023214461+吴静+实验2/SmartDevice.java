public abstract class SmartDevice {
    private String deviceId;
    private String deviceName;
    private boolean isOn;

    public SmartDevice(String deviceId, String deviceName) {
        this.deviceId = deviceId;
        this.deviceName = deviceName;
        this.isOn = false;
    }

    public void turnOn() {
        isOn = true;
        System.out.println(deviceName + "已开启");
    }

    public void turnOff() {
        isOn = false;
        System.out.println(deviceName + "已关闭");
    }

    public String getStatus() {
        return String.format("设备ID: %s, 名称: %s, 状态: %s", deviceId, deviceName, (isOn ? "开" : "关"));
    }

    public boolean isOn() {
        return isOn;
    }

    public String getDeviceId() {
        return deviceId;
    }

    public abstract String getDeviceType();
}
