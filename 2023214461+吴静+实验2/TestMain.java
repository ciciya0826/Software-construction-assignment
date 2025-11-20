public class TestMain {
    public static void main(String[] args) {
        HomeManager manager = new HomeManager();

        SmartLight light = new SmartLight("L001", "灯");
        SmartAC ac = new SmartAC("A001", "空调");
        SmartCurtain curtain = new SmartCurtain("C001", "窗帘");

        manager.addDevice(light);
        manager.addDevice(ac);
        manager.addDevice(curtain);

        manager.turnOnDevice("L001");
        light.setBrightness(80);

        manager.turnOnDevice("A001");
        ac.setTemperature(22);
        ac.setMode("制热");

        curtain.setOpenPercentage(70);

        System.out.println("\n当前设备状态：");
        manager.displayAllDevices();
    }
}
