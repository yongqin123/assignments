
SELECT CONCAT("A purchase with the purchase ID of ",ONLINEPURCHASE.PurchaseID," is an online purchase of type ", ONLINEPURCHASE.OnlineType," and also a walkin purchase of location ", WALKINPURCHASE.ShopLocation) AS Message FROM WALKINPURCHASE INNER JOIN ONLINEPURCHASE ON WALKINPURCHASE.PurchaseID = ONLINEPURCHASE.PurchaseID;

